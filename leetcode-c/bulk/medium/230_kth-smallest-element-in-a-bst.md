# 0230. Kth Smallest Element in a BST《二元搜尋樹中的第 K 小元素》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, binary-search-tree, binary-tree
- **題目連結**: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
- **程式碼**: [`230_kth-smallest-element-in-a-bst.c`](./230_kth-smallest-element-in-a-bst.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元搜尋樹根節點與整數 k，回傳所有節點值中第 k 小的值，k 以 1 起算。題目也詢問當樹常插入、刪除且需頻繁查詢時，如何進一步最佳化。

**思路**：每次遞迴先計算目前節點左子樹大小，再據此判斷答案是根、位於左子樹，或位於調整後 k 的右子樹。

## Problem Statement (English)

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
Example 1:
Example 2:
Constraints:
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

## 範例 Examples

```text
Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
```

## 限制 Constraints

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104

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
int kthSmallest(struct TreeNode* root, int k) {
    
}
```
