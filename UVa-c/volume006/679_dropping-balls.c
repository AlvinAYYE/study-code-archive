/*
 * ==========================================================================
 * UVa 679 - Dropping Balls
 * Title-CN: 下落的小球 (滿二元樹二進位路徑映射)
 * Difficulty: UVa Star 2
 * Tags: binary-tree, math, bit-manipulation
 * URL: https://onlinejudge.org/external/6/679.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the final leaf node number of the I-th dropped ball in a full binary tree of depth D.
 *
 * [中文] 題目說明:
 *     在深度為 D 的滿二元樹中連續投入 I 個球 (遇到開關為 false 往左並切換為 true，否則往右)，求第 I 個球落入的葉節點編號。
 *
 * [EN] Approach:
 *     Avoid O(I*D) simulation. Determine left/right step directly via parity of (I - 1): odd goes right, even goes left.
 * [中文] 思路:
 *     位元奇偶性數學規律：每次下落方向直接由當前是第幾顆球的二進位位元決定，時間複雜度由 O(I) 降至 O(D)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva679(int d, int I) {
    int node = 1;
    for (int i = 1; i < d; i++) {
        if (I % 2 == 1) {
            node = node * 2;
            I = (I + 1) / 2;
        } else {
            node = node * 2 + 1;
            I = I / 2;
        }
    }
    return node;
}

int main(void) {

    int ok = (solve_uva679(4, 2) == 12);
    printf("%s: UVa 679 - Dropping Balls\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
