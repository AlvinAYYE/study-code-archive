/*
 * ==========================================================================
 * UVa 599 - The Forrest for the Trees
 * Title-CN: 樹與橡果 (並查集連通分支與孤立點計數)
 * Difficulty: UVa Star 1
 * Tags: graph, dsu, tree
 * URL: https://onlinejudge.org/external/5/599.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given edge list and isolated nodes, count how many trees (size >= 2) and how many acorns (isolated vertices) exist.
 *
 * [中文] 題目說明:
 *     給定無環森林的邊與頂點列表，計算其中由 2 個以上節點構成的「樹木」數量與單獨 1 個節點的「橡果」數量。
 *
 * [EN] Approach:
 *     Disjoint Set Union (DSU) or formula: Trees = (Vertices with degree > 0) - Edges. Acorns = Vertices with degree == 0.
 * [中文] 思路:
 *     無環圖性質：由大於 1 個節點的樹構成的分支數 = (有邊連接的頂點數) - 邊數；橡果即度數為 0 的獨立頂點數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva599(int total_v, int edges_count, int deg_0_count, int *out_trees, int *out_acorns) {
    *out_acorns = deg_0_count;
    int v_in_trees = total_v - deg_0_count;
    *out_trees = (v_in_trees > 0) ? (v_in_trees - edges_count) : 0;
}

int main(void) {

    int trees, acorns;
    solve_uva599(5, 3, 1, &trees, &acorns);
    int ok = (trees == 1 && acorns == 1);
    printf("%s: UVa 599 - The Forrest for the Trees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
