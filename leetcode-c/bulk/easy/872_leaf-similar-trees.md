# 0872. Leaf-Similar Trees《葉節點相似的樹》

- **Difficulty**: Easy
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/leaf-similar-trees/
- **程式碼**: [`872_leaf-similar-trees.c`](./872_leaf-similar-trees.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

二元樹由左到右所有葉節點的值會形成一個葉值序列。若兩棵樹的葉值序列完全相同，便稱為葉節點相似；判斷 root1 與 root2 是否如此。

**思路**：程式先計算節點數以配置陣列，再以左優先的遞迴走訪收集兩棵樹的葉節點值。最後比較兩個葉序列的長度與每個位置的值。

## Problem Statement (English)

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
```

## 限制 Constraints

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].

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
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    
}
```
