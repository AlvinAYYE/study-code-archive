# 0257. Binary Tree Paths《二元樹路徑》

- **Difficulty**: Easy
- **Tags**: string, backtracking, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/binary-tree-paths/
- **程式碼**: [`257_binary-tree-paths.c`](./257_binary-tree-paths.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，回傳所有從根節點到葉節點的路徑，順序不限。葉節點是沒有任何子節點的節點，路徑以 "->" 串接節點值。

**思路**：以深度優先走訪並共用可擴充字串緩衝區，沿途追加節點值與箭頭。走到葉節點時複製目前路徑字串加入答案。

## Problem Statement (English)

Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Input: root = [1]
Output: ["1"]
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

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
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    
}
```
