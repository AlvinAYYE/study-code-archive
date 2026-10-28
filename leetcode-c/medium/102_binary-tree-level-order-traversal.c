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
 * [中文] 題目說明
 *     給定二元樹根節點 root，回傳各節點的層序走訪結果：由上到下逐層處理，
 *     同一層則由左到右排列。每一層要放在一個獨立陣列中。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：root = [3,9,20,null,null,15,7]
 *     輸出：[[3],[9,20],[15,7]]
 *   範例 2：
 *     輸入：root = [1]
 *     輸出：[[1]]
 *   範例 3：
 *     輸入：root = []
 *     輸出：[]
 *
 * [中文] 限制
 *   - 樹的節點數介於 0 到 2000。
 *   - -1000 <= Node.val <= 1000。
 *
 * LeetCode official C stub (函式簽名):
 *   int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 用佇列保存等待處理的節點，先把 root 放入。
 *   2. 每輪開始時，佇列中尚未處理的節點數就是目前層的大小 levelCnt。
 *   3. 取出恰好 levelCnt 個節點，依序記錄值，並把各自的左右子節點放到佇列尾端。
 *   4. 重複到佇列為空；root 為空時直接回傳空答案。
 *   每個節點進出佇列一次，時間複雜度 O(n)，佇列與輸出空間 O(n)。
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
        /* 本輪只處理進入下一層前已在佇列中的節點。 */
        int levelCnt = qt - qh, i, base = qh;
        int *row;
        TreeNode *nd;
        out  = (int **)realloc(out, (size_t)(cnt + 1) * sizeof(int *));
        cols = (int *)realloc(cols, (size_t)(cnt + 1) * sizeof(int));
        row  = (int *)malloc((size_t)levelCnt * sizeof(int));
        for (i = 0; i < levelCnt; ++i) {
            nd = q[base + i];
            row[i] = nd->val;
            if (nd->left) {
                if (qt == qcap)
                    q = (TreeNode **)realloc(q, (size_t)(qcap *= 2) * sizeof(TreeNode *));
                q[qt++] = nd->left;
            }
            if (nd->right) {
                if (qt == qcap)
                    q = (TreeNode **)realloc(q, (size_t)(qcap *= 2) * sizeof(TreeNode *));
                q[qt++] = nd->right;
            }
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
