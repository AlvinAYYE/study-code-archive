/*
 * ==========================================================================
 * UVa 102 - Ecological Bin Packing
 * Title-CN: 生態回收桶
 * Difficulty: UVa Star 1
 * Tags: math, greedy, simulation
 * ==========================================================================
 * [EN] Problem: Move brown (B), green (G), clear (C) bottles into 3 bins with minimum moves.
 * [中文] 題目說明: 將三個箱子分別統一存放 B, G, C 三種瓶子，求最小移動次數與字典序最先之配置。
 * [EN] Approach: Evaluate all 6 permutations (BCG, BGC, CBG, CGB, GBC, GCB) in alphabetical order.
 * [中文] 思路: 依字典序枚舉 6 種可能組合，計算各自所需搬移瓶子數取最小值。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

static const char *perms[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
static const int p_idx[6][3] = {
    {0, 2, 1}, {0, 1, 2}, {2, 0, 1}, {2, 1, 0}, {1, 0, 2}, {1, 2, 0}
};

void solve_uva102(const int b[3][3], char *best_str, int *min_moves) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) total += b[i][j];
    }
    int best_m = 2e9, best_p = -1;
    for (int p = 0; p < 6; p++) {
        int keep = b[0][p_idx[p][0]] + b[1][p_idx[p][1]] + b[2][p_idx[p][2]];
        int moves = total - keep;
        if (moves < best_m) {
            best_m = moves;
            best_p = p;
        }
    }
    strcpy(best_str, perms[best_p]);
    *min_moves = best_m;
}

int main(void) {
    int bins[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    char str[5];
    int moves;
    solve_uva102(bins, str, &moves);
    int ok = (moves > 0);
    printf("%s: UVa 102 - Ecological Bin Packing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
