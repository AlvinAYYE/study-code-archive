# 0938. Range Sum of BST《二元搜尋樹的範圍總和》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/range-sum-of-bst/
- **程式碼**: [`938_range-sum-of-bst.c`](./938_range-sum-of-bst.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元搜尋樹根節點與整數 low、high，請計算所有節點值落在閉區間 [low, high] 內的總和。

**思路**：遞迴利用 BST 性質剪枝：節點值過小只搜尋右子樹，過大只搜尋左子樹，落在範圍內則累加節點與兩側子樹。

## Problem Statement (English)

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.

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
int rangeSumBST(struct TreeNode* root, int low, int high) {
    
}
```
