# 0337. House Robber III《打家劫舍 III》

- **Difficulty**: Medium
- **Tags**: dynamic-programming, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/house-robber-iii/
- **程式碼**: [`337_house-robber-iii.c`](./337_house-robber-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

房屋形成一棵二元樹，若同一晚偷竊兩間直接相連的房屋便會報警。給定根節點 root，請回傳在不偷相鄰父子節點的條件下可取得的最大金額。

**思路**：對每個節點遞迴比較兩種選擇：偷目前節點並加上四個孫節點的最佳值，或不偷目前節點而加上兩個子節點的最佳值。回傳兩者較大者。

## Problem Statement (English)

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
```

## 限制 Constraints

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104

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
int rob(struct TreeNode* root) {
    
}
```
