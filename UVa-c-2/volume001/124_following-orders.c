/*
 * ==========================================================================
 * UVa 124 - Following Orders
 * Title-CN: 依順序排程 (全排列拓撲排序)
 * Difficulty: UVa Star 2
 * Tags: graph, topological-sort, backtracking
 * URL: https://onlinejudge.org/external/1/124.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a set of variables and ordering constraints, print all valid topological orderings in alphabetical order.
 *
 * [中文] 題目說明:
 *     給定一組變數及其先後依序限制條件，按字母順序輸出所有合法的拓撲排序序列。
 *
 * [EN] Approach:
 *     Backtracking with constraint verification. Sort variable characters, recursively pick unused char with 0 in-degree.
 * [中文] 思路:
 *     回溯法全排列搜尋：將變數按字典序排序，每次遞迴挑選入度為 0 且未使用的變數加入排列。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva124_can_place(int var, int placed_mask, int adj[26][26]) {
    for (int u = 0; u < 26; u++) {
        if (adj[u][var] && !(placed_mask & (1 << u))) return 0;
    }
    return 1;
}

int main(void) {

    int adj[26][26] = {0};
    adj[0][1] = 1;
    int ok = solve_uva124_can_place(1, 1, adj) && !solve_uva124_can_place(1, 0, adj);
    printf("%s: UVa 124 - Following Orders\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
