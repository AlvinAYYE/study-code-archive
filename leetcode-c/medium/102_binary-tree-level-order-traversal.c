/*
 * ==========================================================================
 * LeetCode 102. Binary Tree Level Order Traversal
 * Title-CN: 二叉樹的層序遍歷
 * Difficulty: Medium
 * Tags: tree, breadthfirst-search, binary-tree
 * URL: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given the root of a binary tree, return the level order traversal of its
 *     nodes' values. (i.e., from left to right, level by level).
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     回傳二叉樹由上而下、逐層節點值。
 *
 * Examples:
 *   Example 1:
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: [[3],[9,20],[15,7]]
 *   Example 2:
 *     Input: root = [1]
 *     Output: [[1]]
 *   Example 3:
 *     Input: root = []
 *     Output: []
 *
 * Constraints:
 *   - The number of nodes in the tree is in the range [0, 2000].
 *   - -1000 <= Node.val <= 1000
 *
 * LeetCode official C stub (函式簽名):
 *   int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Classic BFS: process one whole level per queue batch. Time O(n), space O(n).
 * [中文] 思路: 標準 BFS：每次把整層節點出列，記錄該層值再壓入下一層。時間 O(n)、空間 O(n)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* LeetCode provides this definition / LeetCode 已提供 */
struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };
typedef struct TreeNode TreeNode;

/* ---------- LeetCode submission / 提交區 ---------- */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    int **out = NULL; int *cols = NULL; int cnt = 0;
    TreeNode **q; int qh = 0, qt = 0, qcap = 16;
    *returnSize = 0; *returnColumnSizes = NULL;
    if (!root) return NULL;
    q = (TreeNode **)malloc((size_t)qcap * sizeof(TreeNode *));
    q[qt++] = root;
    while (qh < qt) {
        int levelCnt = qt - qh, i, base = qh;
        int *row;
        TreeNode *nd;
        out  = (int **)realloc(out, (size_t)(cnt + 1) * sizeof(int *));
        cols = (int *)realloc(cols, (size_t)(cnt + 1) * sizeof(int));
        row  = (int *)malloc((size_t)levelCnt * sizeof(int));
        for (i = 0; i < levelCnt; ++i) {
            nd = q[base + i];
            row[i] = nd->val;
            if (nd->left)  { if (qt == qcap) q = (TreeNode **)realloc(q, (size_t)(qcap *= 2) * sizeof(TreeNode *)); q[qt++] = nd->left; }
            if (nd->right) { if (qt == qcap) q = (TreeNode **)realloc(q, (size_t)(qcap *= 2) * sizeof(TreeNode *)); q[qt++] = nd->right; }
        }
        qh = base + levelCnt;
        out[cnt] = row; cols[cnt] = levelCnt; cnt++;
    }
    free(q);
    *returnSize = cnt;
    *returnColumnSizes = cols;
    return out;
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
static int roweq(int *a, int n, int *e) {
    int i; for (i = 0; i < n; ++i) if (a[i] != e[i]) return 0;
    return 1;
}

int main(void) {
    int ok = 1, rs = 0; int *cols = NULL; int **out;
    int l0[] = {3}, l1[] = {9, 20}, l2[] = {15, 7};
    TreeNode *root = node(3, node(9, NULL, NULL), node(20, node(15, NULL, NULL), node(7, NULL, NULL)));
    out = levelOrder(root, &rs, &cols);
    ok = ok && rs == 3;
    ok = ok && cols[0] == 1 && roweq(out[0], 1, l0);
    ok = ok && cols[1] == 2 && roweq(out[1], 2, l1);
    ok = ok && cols[2] == 2 && roweq(out[2], 2, l2);
    treefree(root);

    rs = 0; out = levelOrder(NULL, &rs, &cols);
    ok = ok && rs == 0 && out == NULL;
    printf("%s: 102 binary-tree-level-order-traversal\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
