# 0129. Sum Root to Leaf Numbers《根節點到葉節點數字之和》

- **Difficulty**: Medium
- **Tags**: tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/sum-root-to-leaf-numbers/
- **程式碼**: [`129_sum-root-to-leaf-numbers.c`](./129_sum-root-to-leaf-numbers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定一棵節點值只含 0 至 9 的二元樹，每條根到葉路徑代表一個十進位數字。請回傳所有根到葉數字的總和。測資保證答案可放入 32 位元帶符號整數。樹有 1 至 1000 個節點，深度不超過 10。

**思路**：DFS 向下時將累積值更新為 cur×10 加上目前數字，抵達葉節點便回傳該數字，最後加總左右子樹結果。

## Problem Statement (English)

You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.

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
int sumNumbers(struct TreeNode* root) {
    
}
```
