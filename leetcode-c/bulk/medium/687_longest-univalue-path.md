# 0687. Longest Univalue Path《最長同值路徑》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/longest-univalue-path/
- **程式碼**: [`687_longest-univalue-path.c`](./687_longest-univalue-path.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，找出路徑上所有節點值都相同的最長路徑，該路徑不一定經過根節點。路徑長度以兩端節點之間的邊數計算。

**思路**：以後序遞迴回傳從目前節點向下、且值相同的最長單支長度。若左右子節點同值便合併兩支更新全域最大值，最後換算為邊數。

## Problem Statement (English)

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between them.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.

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
int longestUnivaluePath(struct TreeNode* root) {
    
}
```
