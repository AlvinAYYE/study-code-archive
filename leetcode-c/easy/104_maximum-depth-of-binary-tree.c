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
 *     回傳二叉樹最深節點的深度（根節點深度計為 1）。
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
 * [中文] 思路: 遞迴：深度 = 1 + max(左子樹深度, 右子樹深度)，空節點回傳 0。時間 O(n)、空間 O(h)。
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
