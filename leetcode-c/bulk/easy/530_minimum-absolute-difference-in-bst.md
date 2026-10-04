# 0530. Minimum Absolute Difference in BST《二元搜尋樹的最小絕對差》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
- **程式碼**: [`530_minimum-absolute-difference-in-bst.c`](./530_minimum-absolute-difference-in-bst.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵二元搜尋樹，回傳任兩個不同節點值之間的最小絕對差。樹至少含有兩個節點。

**思路**：利用 BST 的中序走訪會得到遞增值序列，只需保存前一個走訪值並更新相鄰值差的最小值。

## Problem Statement (English)

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
Example 1:
Example 2:
Constraints:
Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

## 範例 Examples

```text
Input: root = [4,2,6,1,3]
Output: 1

Input: root = [1,0,48,null,null,12,49]
Output: 1
```

## 限制 Constraints

The number of nodes in the tree is in the range [2, 104].
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
int getMinimumDifference(struct TreeNode* root) {
    
}
```
