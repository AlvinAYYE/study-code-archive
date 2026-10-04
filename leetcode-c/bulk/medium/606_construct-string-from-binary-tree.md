# 0606. Construct String from Binary Tree《根據二叉樹建立字串》

- **Difficulty**: Medium
- **Tags**: string, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/construct-string-from-binary-tree/
- **程式碼**: [`606_construct-string-from-binary-tree.c`](./606_construct-string-from-binary-tree.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二叉樹根節點，依前序走訪建立樹的字串表示法。子樹以括號包住，應省略不影響樹結構的空括號；但若節點沒有左子樹卻有右子樹，必須保留空的左括號對來表示結構。

**思路**：遞迴以前序走訪輸出節點值與括號。依左右子樹是否存在決定要輸出哪些括號，特別為只有右子樹的情況先寫入 "()"。

## Problem Statement (English)

Given the root node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the empty parenthesis pairs. And it will be "1(2(4))(3)".

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except the () after 2 is necessary to indicate the absence of a left child for 2 and the presence of a right child.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
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
char* tree2str(struct TreeNode* root) {
    
}
```
