/*
 * ==========================================================================
 * UVa 536 - Tree Recovery
 * Title-CN: 二元樹還原 (前序與中序重構後序走訪)
 * Difficulty: UVa Star 1
 * Tags: binary-tree, recursion
 * URL: https://onlinejudge.org/external/5/536.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given preorder and inorder traversals of a binary tree, reconstruct and print postorder traversal.
 *
 * [中文] 題目說明:
 *     給定二元樹的前序遍歷與中序遍歷字串，遞迴重構二元樹並輸出後序遍歷字串。
 *
 * [EN] Approach:
 *     Root is pre[0]. Find root index in inorder to divide left and right subtrees. Recurse left, right, then print root.
 * [中文] 思路:
 *     前序首字元即為當前樹根；在中序中找到該字元位置即可分割出左子樹與右子樹範圍，遞迴走訪左、右後輸出根結點。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void build_postorder(const char *pre, const char *in, int n, char *out, int *out_idx) {
    if (n <= 0) return;
    char root = pre[0];
    int k = 0;
    while (k < n && in[k] != root) k++;
    build_postorder(pre + 1, in, k, out, out_idx);
    build_postorder(pre + 1 + k, in + k + 1, n - k - 1, out, out_idx);
    out[(*out_idx)++] = root;
}

void solve_uva536(const char *pre, const char *in, char *post) {
    int idx = 0;
    build_postorder(pre, in, (int)strlen(pre), post, &idx);
    post[idx] = '\0';
}

int main(void) {

    char post[10];
    solve_uva536("DBACEGF", "ABCDEFG", post);
    int ok = (strcmp(post, "ACBFGED") == 0);
    printf("%s: UVa 536 - Tree Recovery\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
