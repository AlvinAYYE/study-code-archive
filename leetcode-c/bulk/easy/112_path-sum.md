# 0112. Path Sum《路徑總和》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/path-sum/
- **程式碼**: [`112_path-sum.c`](./112_path-sum.c) — 本專案自行撰寫並通過官方示例驗證

## 題目說明（中文）

給定二元樹根節點與整數 targetSum，判斷是否存在一條根到葉的路徑，其節點值總和恰好等於 targetSum。葉節點是沒有子節點的節點，空樹不存在符合條件的路徑。存在時回傳 true，否則回傳 false。樹最多有 5000 個節點，節點值與 targetSum 均介於 -1000 至 1000。

**思路**：遞迴向下傳遞扣除目前節點值後的目標和，並在葉節點直接比較其值是否等於剩餘目標。

## Problem Statement (English)

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

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
bool hasPathSum(struct TreeNode* root, int targetSum) {
    
}
```
