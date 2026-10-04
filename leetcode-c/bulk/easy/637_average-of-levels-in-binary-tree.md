# 0637. Average of Levels in Binary Tree《二叉樹的層平均值》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/average-of-levels-in-binary-tree/
- **程式碼**: [`637_average-of-levels-in-binary-tree.c`](./637_average-of-levels-in-binary-tree.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二叉樹根節點，計算每一層所有節點值的平均數，並依層數由上到下回傳。節點值可為負數，結果以浮點數表示。

**思路**：先遞迴取得樹高以配置陣列，再以 DFS 按深度累加每層的節點和與節點數。最後逐層以總和除以計數得到平均值。

## Problem Statement (English)

Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

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
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    
}
```
