/*
 * ==========================================================================
 * UVa 712 - S-Trees
 * Title-CN: 布林決策樹 (S-樹)
 * Difficulty: Easy
 * Tags: Binary Tree, Bit Manipulation
 * URL: https://onlinejudge.org/external/7/712.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate evaluation on a fully balanced boolean decision tree (S-tree) given variable assignment vectors.
 *
 * [中文] 題目說明:
 *     給定變數排列順序與各賦值向量，在完全平衡的布林決策樹上沿左右子樹遍歷求葉節點結果值。
 *
 * [EN] Approach:
 *     Compute binary index of leaf node: each variable x_i in order determines whether to take the left branch (0) or right branch (1).
 * [中文] 思路:
 *     依變數順序取出賦值 0 或 1 作為二進位位的權重，組合出葉節點的下標直接取得輸出值。
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

char eval_s_tree(int depth, const int *var_order, const char *leaves, const char *assignment) {
    int idx = 0;
    for (int i = 0; i < depth; i++) {
        int v_idx = var_order[i] - 1;
        int bit = assignment[v_idx] - '0';
        idx = (idx << 1) | bit;
    }
    return leaves[idx];
}

int main(void) {

    int order[] = {1, 2, 3};
    char leaves[] = "00000111";
    char out = eval_s_tree(3, order, leaves, "110"); // binary 6 -> '1'
    int ok = (out == '1');
    printf("%s: UVa 712 - S-Trees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
