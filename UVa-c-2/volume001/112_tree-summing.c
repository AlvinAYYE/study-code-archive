/*
 * ==========================================================================
 * UVa 112 - Tree Summing
 * Title-CN: 二元樹路徑和
 * Difficulty: UVa Star 2
 * Tags: recursion, parsing, tree
 * URL: https://onlinejudge.org/external/1/112.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given target sum and S-expression binary tree, determine if there exists root-to-leaf path with this sum.
 *
 * [中文] 題目說明:
 *     解析括號 S-expression 表達的二元樹，判定是否存在一條從根結點到葉節點的路徑和等於目標值。
 *
 * [EN] Approach:
 *     Recursive descent parsing. If node is leaf (both subtrees empty), check current_sum == target.
 * [中文] 思路:
 *     遞迴下降解析括號樹結構。當遞迴到左右子樹皆為空的葉節點時，檢查累積路徑和是否恰等於目標值。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct TNode {
    int val;
    struct TNode *left, *right;
} TNode;

int has_path_sum(TNode *root, int target, int cur) {
    if (!root) return 0;
    cur += root->val;
    if (!root->left && !root->right) return cur == target;
    return has_path_sum(root->left, target, cur) || has_path_sum(root->right, target, cur);
}

int main(void) {

    TNode l = {4, NULL, NULL};
    TNode r = {7, NULL, NULL};
    TNode root = {5, &l, &r};
    int ok = has_path_sum(&root, 9, 0) && !has_path_sum(&root, 10, 0);
    printf("%s: UVa 112 - Tree Summing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
