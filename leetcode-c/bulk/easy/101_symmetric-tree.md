# 0101. Symmetric Tree《對稱二元樹》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/symmetric-tree/
- **程式碼**: [`101_symmetric-tree.c`](./101_symmetric-tree.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，判斷它是否以中心為軸左右鏡像對稱。空樹可視為對稱。樹的節點數最多為 1000。

**思路**：以逐層陣列保存節點（包含空位置），每層從兩端向中間比對鏡像位置的空值與節點值。每輪再依序建立下一層的左右子節點。

## Problem Statement (English)

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 1000].
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
bool isSymmetric(struct TreeNode* root) {
    
}
```
