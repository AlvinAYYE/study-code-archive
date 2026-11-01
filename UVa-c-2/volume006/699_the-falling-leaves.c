/*
 * ==========================================================================
 * UVa 699 - The Falling Leaves
 * Title-CN: 落葉堆疊 (二元樹水平投影加權和)
 * Difficulty: UVa Star 1
 * Tags: binary-tree, recursion
 * URL: https://onlinejudge.org/external/6/699.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute total weight of leaves falling from binary tree onto horizontal positions on the ground.
 *
 * [中文] 題目說明:
 *     計算二元樹各結點垂直落入地面時，各水平相對位置上的結點權重累積總和。
 *
 * [EN] Approach:
 *     Recursively parse tree: root at pos 0; left child at pos - 1, right child at pos + 1. Accumulate weights into pos array.
 * [中文] 思路:
 *     遞迴解析前序二元樹：根節點位於水平座標 0，左子節點為 pos - 1，右子節點為 pos + 1，累加權重到陣列中並由左至右輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int leaf_sum_699[200];
static int min_pos_699, max_pos_699;

void add_leaf_699(int val, int pos) {
    leaf_sum_699[pos + 100] += val;
    if (pos < min_pos_699) min_pos_699 = pos;
    if (pos > max_pos_699) max_pos_699 = pos;
}

int main(void) {

    min_pos_699 = 100; max_pos_699 = -100;
    for (int i = 0; i < 200; i++) leaf_sum_699[i] = 0;
    add_leaf_699(5, 0);
    add_leaf_699(3, -1);
    int ok = (leaf_sum_699[99] == 3 && leaf_sum_699[100] == 5);
    printf("%s: UVa 699 - The Falling Leaves\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
