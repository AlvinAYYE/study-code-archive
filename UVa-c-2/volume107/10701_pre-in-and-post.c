/*
 * ==========================================================================
 * UVa 10701 - Pre, in and post
 * Title-CN: 前序、中序求後序遍歷
 * Difficulty: Easy
 * Tags: Binary Tree, Tree Traversal, Recursion
 * URL: https://onlinejudge.org/external/107/10701.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given pre-order and in-order traversals of a binary tree with distinct characters, reconstruct and output its post-order traversal.
 *
 * [中文] 題目說明:
 *     給定二元樹的前序與中序遍歷序列，重建二元樹並輸出其後序遍歷序列。
 *
 * [EN] Approach:
 *     Root is pre[0]. Find root in inorder sequence to split into left and right subtrees. Recursively build postorder (left, right, root).
 * [中文] 思路:
 *     前序首字元為根節點，在中序序列中找到該根節點劃分左右子樹，遞迴構建左、右、根後序序列。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

void build_postorder(const char *pre, const char *in, int n, char *out, int *out_idx) {
    if (n <= 0) return;
    char root = pre[0];
    int r_idx = 0;
    while (r_idx < n && in[r_idx] != root) r_idx++;
    build_postorder(pre + 1, in, r_idx, out, out_idx);
    build_postorder(pre + 1 + r_idx, in + r_idx + 1, n - 1 - r_idx, out, out_idx);
    out[(*out_idx)++] = root;
}

int main(void) {

    char post[10];
    int idx = 0;
    build_postorder("DBACEGF", "ABCDEFG", 7, post, &idx);
    post[idx] = '\0';
    int ok = (strcmp(post, "ACBFGED") == 0);
    printf("%s: UVa 10701 - Pre, in and post\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
