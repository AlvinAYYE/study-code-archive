/*
 * ==========================================================================
 * UVa 315 - Network
 * Title-CN: 關鍵伺服器頂點 (Tarjan 割點演算法)
 * Difficulty: UVa Star 2
 * Tags: graph, tarjan, articulation-points
 * URL: https://onlinejudge.org/external/3/315.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find number of articulation points (critical nodes whose removal disconnects the network).
 *
 * [中文] 題目說明:
 *     在無向連通網路中求割點 (關節點) 的總數量，即移除該點會導致網路分裂不連通的伺服器個數。
 *
 * [EN] Approach:
 *     Tarjan's DFS articulation points algorithm tracking discovery time dfn[u] and lowest reachable time low[u].
 * [中文] 思路:
 *     以 Tarjan 演算法深度優先遍歷圖，維護時間戳 dfn 與追溯值 low。若非根節點存在 low[v] >= dfn[u] 則 u 為割點。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int dfn_315[105], low_315[105], is_cut_315[105], timer_315;
static int adj_315[105][105], deg_315[105];

void tarjan_315(int u, int p) {
    dfn_315[u] = low_315[u] = ++timer_315;
    int children = 0;
    for (int i = 0; i < deg_315[u]; i++) {
        int v = adj_315[u][i];
        if (v == p) continue;
        if (!dfn_315[v]) {
            children++;
            tarjan_315(v, u);
            if (low_315[v] < low_315[u]) low_315[u] = low_315[v];
            if (p != 0 && low_315[v] >= dfn_315[u]) is_cut_315[u] = 1;
        } else if (dfn_315[v] < low_315[u]) {
            low_315[u] = dfn_315[v];
        }
    }
    if (p == 0 && children > 1) is_cut_315[u] = 1;
}

int solve_uva315(int n) {
    timer_315 = 0;
    for (int i = 1; i <= n; i++) { dfn_315[i] = low_315[i] = is_cut_315[i] = 0; }
    tarjan_315(1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (is_cut_315[i]) cnt++;
    return cnt;
}

int main(void) {

    deg_315[1] = 1; adj_315[1][0] = 2;
    deg_315[2] = 2; adj_315[2][0] = 1; adj_315[2][1] = 3;
    deg_315[3] = 1; adj_315[3][0] = 2;
    int ok = (solve_uva315(3) == 1);
    printf("%s: UVa 315 - Network\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
