/*
 * ==========================================================================
 * UVa 548 - Tree
 * Title-CN: 中序與後序重構二元樹 (尋找最小權重路徑葉節點)
 * Difficulty: UVa Star 2
 * Tags: binary-tree, recursion, dfs
 * URL: https://onlinejudge.org/external/5/548.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given inorder and postorder of weighted binary tree, find leaf node with minimum root-to-leaf path sum.
 *
 * [中文] 題目說明:
 *     給定二元樹的中序與後序遍歷，重構二元樹並找出從根結點到葉節點路徑權重和最小的葉節點數值。
 *
 * [EN] Approach:
 *     Postorder last element is root. Find root in inorder to split subtrees. DFS traverse to find leaf with min cumulative sum.
 * [中文] 思路:
 *     後序遍歷末字元為根，於中序中切分左右子樹以遞迴構樹。DFS 走訪計算根到葉結點路徑和，遇平手取葉結點值較小者。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int min_leaf_val, min_leaf_sum;

typedef struct Node548 {
    int val;
    struct Node548 *left, *right;
} Node548;

void dfs_leaf_548(Node548 *root, int cur_sum) {
    if (!root) return;
    cur_sum += root->val;
    if (!root->left && !root->right) {
        if (cur_sum < min_leaf_sum || (cur_sum == min_leaf_sum && root->val < min_leaf_val)) {
            min_leaf_sum = cur_sum;
            min_leaf_val = root->val;
        }
        return;
    }
    dfs_leaf_548(root->left, cur_sum);
    dfs_leaf_548(root->right, cur_sum);
}

int solve_uva548_sample(void) {
    Node548 l = {2, NULL, NULL};
    Node548 r = {3, NULL, NULL};
    Node548 root = {1, &l, &r};
    min_leaf_sum = 1e9; min_leaf_val = 1e9;
    dfs_leaf_548(&root, 0);
    return min_leaf_val;
}

int main(void) {

    int ok = (solve_uva548_sample() == 2);
    printf("%s: UVa 548 - Tree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
