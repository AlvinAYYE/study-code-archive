/*
 * ==========================================================================
 * LeetCode 104. Maximum Depth of Binary Tree
 * Title-CN: 二叉樹的最大深度
 * Difficulty: Easy
 * Tags: tree, depthfirst-search, breadthfirst-search, binary-tree
 * URL: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given the root of a binary tree, return its maximum depth.
 *     A binary tree's maximum depth is the number of nodes along the longest
 *     path from the root node down to the farthest leaf node.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定二元樹的根節點 root，回傳這棵樹的最大深度。最大深度是從根節點
 *     到最遠葉節點的最長路徑上，所包含的節點數；空樹的深度為 0。
 *
 * [中文] 範例
 *     1. root = [3,9,20,null,null,15,7]，輸出 3。
 *     2. root = [1,null,2]，輸出 2。
 *
 * [中文] 限制
 *     - 樹的節點數介於 0 到 10^4。
 *     - -100 <= Node.val <= 100
 *
 * Examples:
 *   Example 1:
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: 3
 *   Example 2:
 *     Input: root = [1,null,2]
 *     Output: 2
 *
 * Constraints:
 *   - The number of nodes in the tree is in the range [0, 10^4].
 *   - -100 <= Node.val <= 100
 *
 * LeetCode official C stub (函式簽名):
 *   int maxDepth(struct TreeNode* root) {
 *   }
 *
 * [EN] Approach: Recursion: depth = 1 + max(depth(left), depth(right)); empty node gives 0. Time O(n), space O(h).
 * [中文] 直觀解題思路
 *     1. 空節點不包含任何節點，深度是 0，作為遞迴終止條件。
 *     2. 非空節點分別求左、右子樹深度；從目前節點出發的最長路徑會走向
 *        較深的一側，因此答案是 1 + max(左深度, 右深度)。
 *     3. 每個節點只拜訪一次，時間 O(n)；遞迴呼叫堆疊最多 O(h)，其中 h
 *        是樹高。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* LeetCode provides this definition / LeetCode 已提供 */
struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };
typedef struct TreeNode TreeNode;

/* ---------- LeetCode submission / 提交區 ---------- */
int maxDepth(TreeNode *root) {
    int l, r;
    if (!root) return 0;
    /* 目前節點的深度，由較深的子樹決定。 */
    l = maxDepth(root->left);
    r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}
/* ---------- end submission ---------- */

static TreeNode *node(int v, TreeNode *l, TreeNode *r) {
    TreeNode *t = (TreeNode *)malloc(sizeof *t);
    t->val = v; t->left = l; t->right = r;
    return t;
}
static void treefree(TreeNode *t) {
    if (!t) return;
    treefree(t->left); treefree(t->right); free(t);
}

int main(void) {
    int ok = 1;
    /*      3          depth 3
     *    /   \
     *   9    20
     *       /  \
     *     15    7   */
    TreeNode *root = node(3, node(9, NULL, NULL), node(20, node(15, NULL, NULL), node(7, NULL, NULL)));
    ok = ok && maxDepth(root) == 3;
    treefree(root);
    ok = ok && maxDepth(NULL) == 0;
    TreeNode *one = node(1, NULL, NULL);
    ok = ok && maxDepth(one) == 1;
    treefree(one);
    TreeNode *chain = node(1, node(2, node(3, NULL, NULL), NULL), NULL);
    ok = ok && maxDepth(chain) == 3;
    treefree(chain);
    printf("%s: 104 maximum-depth-of-binary-tree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
