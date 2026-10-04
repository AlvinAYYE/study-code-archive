# 0113. Path Sum II《路徑總和 II》

- **Difficulty**: Medium
- **Tags**: backtracking, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/path-sum-ii/
- **程式碼**: [`113_path-sum-ii.c`](./113_path-sum-ii.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點與 targetSum，回傳所有節點值總和等於 targetSum 的根到葉路徑。每條結果必須是節點值組成的串列，而非節點參考。根到葉路徑從根開始並在任一葉節點結束，葉節點沒有子節點。樹最多有 5000 個節點，節點值與 targetSum 均介於 -1000 至 1000。

**思路**：以 DFS 維護目前路徑與剩餘和；抵達符合剩餘和的葉節點時，複製堆疊中的路徑到結果陣列。

## Problem Statement (English)

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Input: root = [1,2,3], targetSum = 5
Output: []

Input: root = [1,2], targetSum = 0
Output: []
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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    
}
```
