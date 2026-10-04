# 0404. Sum of Left Leaves《左葉子之和》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/sum-of-left-leaves/
- **程式碼**: [`404_sum-of-left-leaves.c`](./404_sum-of-left-leaves.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵二元樹的根節點，回傳所有左葉節點數值的總和。葉節點沒有任何子節點；左葉節點則必須同時是其父節點的左子節點與葉節點。

**思路**：以遞迴走訪整棵樹，遞迴參數記錄目前節點是否為左子節點。若目前節點是左葉節點便累加其值。

## Problem Statement (English)

Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Input: root = [1]
Output: 0
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000

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
int sumOfLeftLeaves(struct TreeNode* root) {
    
}
```
