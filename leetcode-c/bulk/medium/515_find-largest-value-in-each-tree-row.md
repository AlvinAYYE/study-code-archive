# 0515. Find Largest Value in Each Tree Row《每個樹列中的最大值》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, breadth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
- **程式碼**: [`515_find-largest-value-in-each-tree-row.c`](./515_find-largest-value-in-each-tree-row.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹的根節點，請回傳一個陣列，其中第 i 個元素為樹第 i 層的最大節點值，層數從 0 開始計算。樹的節點數可為 0 至 10^4，節點值可為負數。

**思路**：程式先以遞迴求出樹高與節點數，再用佇列做廣度優先走訪，並依節點所屬層數更新該層的最大值。

## Problem Statement (English)

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Input: root = [1,2,3]
Output: [1,3]
```

## 限制 Constraints

The number of nodes in the tree will be in the range [0, 104].
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
int* largestValues(struct TreeNode* root, int* returnSize) {
    
}
```
