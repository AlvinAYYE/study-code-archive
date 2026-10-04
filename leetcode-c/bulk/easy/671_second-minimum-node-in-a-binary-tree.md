# 0671. Second Minimum Node In a Binary Tree《二叉樹中第二小的節點》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
- **程式碼**: [`671_second-minimum-node-in-a-binary-tree.c`](./671_second-minimum-node-in-a-binary-tree.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵特殊二叉樹，每個節點要麼有兩個子節點、要麼沒有子節點，且內部節點值恆等於兩個子節點值的較小者。找出整棵樹節點值集合中的第二小不同值；若不存在則回傳 -1。

**思路**：以前序走訪所有節點，同時維護目前最小值與大於最小值的最小候選值。走訪結束後若沒有第二小候選值便回傳 -1。

## Problem Statement (English)

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.
Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
If no such second minimum value exists, output -1 instead.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 25].
1 <= Node.val <= 231 - 1
root.val == min(root.left.val, root.right.val) for each internal node of the tree.

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
int findSecondMinimumValue(struct TreeNode* root) {
    
}
```
