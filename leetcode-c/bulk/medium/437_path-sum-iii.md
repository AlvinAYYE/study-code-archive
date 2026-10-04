# 0437. Path Sum III《路徑總和 III》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/path-sum-iii/
- **程式碼**: [`437_path-sum-iii.c`](./437_path-sum-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點與 targetSum，回傳節點值總和等於 targetSum 的向下路徑數量。路徑不必從根節點開始或在葉節點結束，但只能由父節點走向子節點。

**思路**：對每個節點都以它為起點向下遞迴，逐節點扣除剩餘目標並在歸零時計數。主遞迴再對左右子樹重複作為新起點的搜尋。

## Problem Statement (English)

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

## 限制 Constraints

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
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
int pathSum(struct TreeNode* root, int targetSum) {
    
}
```
