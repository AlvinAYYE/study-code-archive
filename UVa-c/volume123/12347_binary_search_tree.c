/*
 * ==========================================================================
 * UVa 12347 - Binary Search Tree
 * Title-CN: 二元搜尋樹前序轉後序
 * Difficulty: Medium
 * Tags: Tree, BST, Recursion
 * URL: https://onlinejudge.org/external/123/12347.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given the preorder traversal sequence of a Binary Search Tree, output its postorder traversal sequence.
 *
 * [中文] 題目描述:
 *     給定二元搜尋樹（BST）的前序遍歷序列，重建該樹並輸出後序遍歷序列。
 *
 * [EN] Approach:
 *     First element is root. Find partition index where elements become greater than root (right subtree). Recursively convert left and right subtrees.
 *
 * [中文] 解題思維:
 *     前序首位為根節點，找到首個大於根節點的位置劃分左右子樹，遞歸處理左子樹、右子樹後輸出根節點。
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

static void bst_post(int *pre, int l, int r, int *post, int *pidx) {
    if (l > r) return;
    int root = pre[l];
    int mid = l + 1;
    while (mid <= r && pre[mid] < root) mid++;
    bst_post(pre, l + 1, mid - 1, post, pidx);
    bst_post(pre, mid, r, post, pidx);
    post[(*pidx)++] = root;
}

void preorder_to_postorder(int *pre, int n, int *post) {
    int pidx = 0;
    bst_post(pre, 0, n - 1, post, &pidx);
}

int main(void) {

    int pre[] = {50, 30, 24, 5, 28, 45, 98, 52, 60};
    int post[9];
    preorder_to_postorder(pre, 9, post);
    // Postorder should end with root (50) and first should be 5
    int ok = (post[8] == 50 && post[0] == 5);
    printf("%s: UVa 12347 - Binary Search Tree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
