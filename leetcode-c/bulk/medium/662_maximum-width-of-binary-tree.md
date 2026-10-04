# 0662. Maximum Width of Binary Tree《二叉樹的最大寬度》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/maximum-width-of-binary-tree/
- **程式碼**: [`662_maximum-width-of-binary-tree.c`](./662_maximum-width-of-binary-tree.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二叉樹，求所有層級中最大的寬度。某層寬度從最左與最右非空節點之間計算，並包含若將樹補成完全二叉樹時夾在中間的空節點位置。答案保證落在 32 位元帶符號整數範圍內。

**思路**：以 BFS 佇列保存節點及其完全二叉樹位置索引，左、右子節點索引分別為 2i 與 2i+1。每層以首末索引之差加一更新最大寬度，單節點層會重設索引以降低溢位風險。

## Problem Statement (English)

Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 3000].
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
int widthOfBinaryTree(struct TreeNode* root) {
    
}
```
