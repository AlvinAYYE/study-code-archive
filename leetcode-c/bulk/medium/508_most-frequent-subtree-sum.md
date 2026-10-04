# 0508. Most Frequent Subtree Sum《出現次數最多的子樹元素和》

- **Difficulty**: Medium
- **Tags**: hash-table, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/most-frequent-subtree-sum/
- **程式碼**: [`508_most-frequent-subtree-sum.c`](./508_most-frequent-subtree-sum.c) — 社群解答（repo BlackDragonF_LeetcodeSolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二元樹根節點，子樹元素和是該節點為根的子樹中所有節點值（包含自身）的總和。回傳出現頻率最高的所有子樹元素和；若平手，全部回傳即可。

**思路**：程式以後序遞迴先求左右子樹和，再加上目前節點值得到子樹和。每個和寫入鏈結串列雜湊表統計頻率，最後收集頻率等於最大值的鍵。

## Problem Statement (English)

Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [5,2,-3]
Output: [2,-3,4]

Input: root = [5,2,-5]
Output: [2]
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

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
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    
}
```
