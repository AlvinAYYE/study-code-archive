# 0124. Binary Tree Maximum Path Sum《二元樹中的最大路徑和》

- **Difficulty**: Hard
- **Tags**: dynamic-programming, tree, depth-first-search, binary-tree
- **題目連結**: https://leetcode.com/problems/binary-tree-maximum-path-sum/
- **程式碼**: [`124_binary-tree-maximum-path-sum.c`](./124_binary-tree-maximum-path-sum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

二元樹中的路徑由相鄰節點間的邊連接，同一節點最多只能出現一次，而且路徑不一定經過根節點。路徑和是路徑上所有節點值的總和。給定根節點 `root`，請回傳任一非空路徑可得到的最大路徑和。

## 解題思路

1. 後序 DFS 先取得左右子樹「從子節點向下延伸」的最佳單邊貢獻。
2. 負貢獻只會讓總和變小，因此將它視為 0，等同不把該側接入路徑。
3. 以目前節點為最高點的完整路徑可以同時連接左右兩側：`node->val + left + right`，用它更新全域最大值。
4. 回傳給父節點的路徑不能分叉，所以只能選擇較大的單側：`node->val + max(left,right)`。
5. 全為負數時，全域最大值以根節點值初始化，仍能保留至少一個節點。

每個節點只造訪一次，時間複雜度為 `O(n)`；遞迴堆疊空間為 `O(h)`，其中 `h` 是樹高。

## Problem Statement (English)

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：root = [1,2,3]
輸出：6
說明：最佳路徑為 2 -> 1 -> 3，總和為 6。

輸入：root = [-10,9,20,null,null,15,7]
輸出：42
說明：最佳路徑為 15 -> 20 -> 7，總和為 42。
```

## 限制

- 樹的節點數介於 `[1, 3 * 10^4]`。
- `-1000 <= Node.val <= 1000`

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
int maxPathSum(struct TreeNode* root) {
    
}
```
